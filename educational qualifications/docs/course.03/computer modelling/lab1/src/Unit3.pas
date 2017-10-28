unit Unit3;
interface
uses
  Classes, SysUtils;
type
  /////////////������ ��������//////////////////////////////////////////////////
  SVETOFOR = class(TThread)
  public
    SV_FLAG: boolean;
    procedure Execute; override;
    procedure SVETOFORS;
  end;
  //////////////////////////////////////////////////////////////////////////////
implementation
uses
  Unit1;
/////////////////������ ����////////////////////////////////////////////////////
procedure SVETOFOR.Execute;
begin
 while true do
   begin
     Synchronize(SVETOFORS);
     Sleep(MAX_SVET*1000);
   end;
end;
////////////////////////////////////////////////////////////////////////////////
procedure SVETOFOR.SVETOFORS;
var i: word;
begin
  ///////����� �������� ������ ����/////////////////////////////////////////////
  if SV_FLAG=true then
   begin
     Form1.Image7.Visible:=false;
     Form1.Image6.Visible:=true;
     SV_FLAG:=false;
   end
  else
   begin
     Form1.Image6.Visible:=false;
     Form1.Image7.Visible:=true;
     SV_FLAG:=true;
   end;
  /////////////////������ ������ ����� ���� ���������///////////////////////////
  for i:=1 to MAX do
    mas[i].flag:=SV_FLAG;   //true and false - ������� � �������
end;
end.
