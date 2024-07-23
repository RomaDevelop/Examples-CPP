object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 433
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 288
    Top = 16
    Width = 185
    Height = 41
    Caption = 'Panel1'
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 8
    Top = 216
    Width = 329
    Height = 209
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object Button1: TButton
    Left = 120
    Top = 8
    Width = 75
    Height = 24
    Caption = 'Button1'
    TabOrder = 2
  end
  object MemoLog: TMemo
    Left = 442
    Top = 88
    Width = 185
    Height = 241
    Lines.Strings = (
      'MemoLog')
    TabOrder = 3
  end
  object Button2: TButton
    Left = 120
    Top = 38
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 120
    Top = 65
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 5
    OnClick = Button3Click
  end
  object RadioButtonPP: TRadioButton
    Left = 8
    Top = 69
    Width = 90
    Height = 17
    Caption = 'RadioButtonPP'
    TabOrder = 6
  end
  object RadioButtonMM: TRadioButton
    Left = 8
    Top = 92
    Width = 113
    Height = 17
    Caption = 'RadioButtonMM'
    TabOrder = 7
  end
  object RadioButtonP5: TRadioButton
    Left = 8
    Top = 115
    Width = 113
    Height = 17
    Caption = 'RadioButtonP5'
    TabOrder = 8
  end
end
