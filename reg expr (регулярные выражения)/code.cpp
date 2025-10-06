https://pvs-studio.ru/ru/blog/posts/cpp/0391/
Совершенно случайно, именно в тот момент я читал книгу "Beautiful Code" (ISBN 9780596510046). 
Эта книга о простых и изящных решениях; в ней я повстречал крайне простую реализацию простых регулярных выражений. 
Буквально несколько десятков строк. И всё!


// Формат регулярного выражения.
// c     Соответсвует любой букве "с"
// .(точка)  Соответсвует любому одному символу
// ^     Соответсвует началу входящей строки
// $     Соответствует концу входящей строки
// *     Соответствует появлению предыдущего символа от нуля до
//       нескольких раз

int matchhere(char *regexp, char *text);
int matchstar(int c, char *regexp, char *text);

// match: поиск соответствий регулярному выражению по всему тексту
int match(char *regexp, char *text)
{
  if (regexp[0] == '^')
    return matchhere(regexp+1, text);
  do { /* нужно посмотреть даже пустую строку */
   if (matchhere(regexp, text))
     return 1;
  } while (*text++ != '\0');
  return 0;
}

// matchhere: поиск соответствий регулярному выражению в начале текста
int matchhere(char *regexp, char *text)
{
   if (regexp[0] == '\0')
     return 1;
   if (regexp[1] == '*')
     return matchstar(regexp[0], regexp+2, text);

   if (regexp[0] == '$' && regexp[1] == '\0')
     return *text == '\0';
   if (*text!='\0' && (regexp[0]=='.' || regexp[0]==*text))
     return matchhere(regexp+1, text+1);
   return 0;
}

// matchstar: поиск регулярного выражения вида с* с начала текста
int matchstar(int c, char *regexp, char *text)
{
  do {   /* символ * соответствует нулю или
            большему количеству появлений */
    if (matchhere(regexp, text))
      return 1;
  } while (*text != '\0' && (*text++ == c || c == '.'));
  return 0;
}