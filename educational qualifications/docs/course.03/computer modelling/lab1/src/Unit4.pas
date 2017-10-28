unit Unit4;
interface
uses
  Classes,SysUtils,Variants;
type
  PESHEHOD = class(TThread)
  protected
    procedure Execute; override;
    procedure DVIGENIE;
  end;
var
  PESH_FLAG: boolean;
implementation
uses Unit1, Unit3;
////////////////////////////////////////////////////////////////////////////////
procedure PESHEHOD.Execute;
begin
 while true do
  begin
    Synchronize(DVIGENIE);
    Sleep(50);
  end;
end;
////////////////////////////////////////////////////////////////////////////////
////��������� �������� �������� - � ����������� �� ��������� � ������������/////
////////////////////////////////////////////////////////////////////////////////
procedure PESHEHOD.DVIGENIE;
begin
if svet.SV_FLAG=true then
begin
 /////////////�������� ����� ��� ����///////////////////////////////////////////
 FLUS:=false;
 if PESH_FLAG=false then
   begin
     //���� ����
     Form1.Image8.Top:=Form1.Image8.Top+MAX_PESH;
   end
 else
   begin
     //���� �����
     Form1.Image8.Top:=Form1.Image8.Top-MAX_PESH;
   end;
 if Form1.Image8.Top>208 then PESH_FLAG:=true;
 if Form1.Image8.Top<108 then PESH_FLAG:=false;
 ///////////////////////////////////////////////////////////////////////////////
end
else
 begin
   //////��������� - ����� �� ������� ������� ������////////////////////////////
   FLUS:=true;
   if PESH_FLAG=false then  //���� ����
    begin
     if (Form1.Image8.Top<=150)and(Form1.Image8.Top>110) then
       Form1.Image8.Top:=Form1.Image8.Top-4;
     if (Form1.Image8.Top>=166)and(Form1.Image8.Top<207) then
       Form1.Image8.Top:=Form1.Image8.Top+4;
    end
   else  //���� �����
    begin
     if (Form1.Image8.Top>=166)and(Form1.Image8.Top<207) then
       Form1.Image8.Top:=Form1.Image8.Top-4;
     if (Form1.Image8.Top<=150)and(Form1.Image8.Top>110) then
       Form1.Image8.Top:=Form1.Image8.Top+4;
    end;
 end;
end;
////////////////////////////////////////////////////////////////////////////////
end.
 