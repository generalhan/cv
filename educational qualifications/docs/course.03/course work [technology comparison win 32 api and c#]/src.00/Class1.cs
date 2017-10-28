///////////////////////////////////////////////////////////////////////////////////////
//
//                  ����: "�������� ����� ������������ ���������� CodeDOM"
//                  ����: 18.04.2006�.
//                  �����: ��������� �.�.
//                  ��������: 1. ������������� ���� �� ������� ���� "TEST.cs"
//                            2. �������������� �������� ���
//                            3. ��������� ��� � ��������� ������
//                             
///////////////////////////////////////////////////////////////////////////////////////
using System;
using System.CodeDom.Compiler;
using Microsoft.CSharp;
using System.Diagnostics; 
using System.CodeDom;
using System.IO;
namespace DOM
{
	///////////////////////////����� �������� ������ ���������/////////////////////////
	class Class1
	{
		[STAThread]
		static void Main(string[] args)
		{
	     COMPILER_CODE TEST_CLASS_COMPILER = new COMPILER_CODE(); //������� ��������� ������ - �������� ������.
		}
	}
	///////////////////////////////////////////////////////////////////////////////////
	public class COMPILER_CODE
	{
		////////////////////////////����������� ������/////////////////////////////////
		public COMPILER_CODE()
		{
         this.GENERATE_CODE_CLIENT();   //����� ������� ������ �������� ��� �� ����
		 this.GOMPILER_CODE_CLIENT();   //����������� ���
		 this.RUN_CODE();               //��������� � ������ ��������� ������
		}	
		/////////////////////������ �������� ��������� � ����//////////////////////////
		private static CodeCompileUnit TEST_Build()
		{
			////////////////////������� ������, ���� ��� ����������////////////////////
			CodeCompileUnit compileUnit = new CodeCompileUnit();
			//////////////////////��������� ����� TEST_Class///////////////////////////
			CodeTypeDeclaration class1 = new CodeTypeDeclaration("TEST_Class");			
			///////////////////////������������ ���� � ������� ����////////////////////
			CodeNamespace samples = new CodeNamespace("NS_Samples");
			/////////��������� ����� ����� � ��������� - "Main()"//////////////////////
			CodeEntryPointMethod start = new CodeEntryPointMethod();
			//////////////////������� ������ �� System.Console �����///////////////////
			CodeTypeReferenceExpression csSystemConsoleType = 
				                     new CodeTypeReferenceExpression("System.Console");
			////////////////���������� Console.WriteLine ���������/////////////////////
			CodeMethodInvokeExpression cs1 = new CodeMethodInvokeExpression( 
				csSystemConsoleType, "WriteLine", 
				new CodePrimitiveExpression("������� CodeDOM!"));
			CodeMethodInvokeExpression cs2 = new CodeMethodInvokeExpression(
				csSystemConsoleType, "WriteLine",
				new CodePrimitiveExpression("��� ����� ���!") );
			CodeMethodInvokeExpression csReadLine = new CodeMethodInvokeExpression(
				csSystemConsoleType, "ReadLine");
			///////////////////////////////////////////////////////////////////////////
            ///////////////////������ ��������� ���������� � ������ ������/////////////
			///////////////////////////////////////////////////////////////////////////
			///////////////////��������� ����� ������������ ���� � �����///////////////
			compileUnit.Namespaces.Add(samples);
			//////////////��������� ����� �.�. System � ������ NS_Samples//////////////
			samples.Imports.Add(new CodeNamespaceImport("System"));            		
			//////////////��������� ����� ��� � ���� �.�.//////////////////////////////
			samples.Types.Add(class1);        
			////////��������� � ������� ��������� ��������� cs1////////////////////////
			start.Statements.Add(cs1);
			start.Statements.Add(cs2);
			start.Statements.Add(csReadLine); //� ������ �������� System.Console.ReadLine
			/////////////////��������� � ������ ����� Main()//////////////////////////
			class1.Members.Add(start);
			return compileUnit;
		}  

        /////////////////////////����������� ���� TEST_CODEDOM.cs//////////////////////
		public void GOMPILER_CODE_CLIENT()
		{
			CodeDomProvider provider = GET_Provider();
		    String sourceFile;
			sourceFile = "TEST_CODEDOM." + provider.FileExtension;
			Console.WriteLine("���������� ���� <<TEST_CODEDOM.cs>> ����������?");
			Console.ReadLine();
			CompilerResults cr = COMPILER_CODE_SERVER(provider,sourceFile,"TEST_CODEDOM.exe");
			Console.WriteLine("��� ������� �������������!");
			Console.ReadLine();
		}
        //////////////////////�����������//////////////////////////////////////////////
		public static CompilerResults COMPILER_CODE_SERVER(CodeDomProvider provider, 
			                                               String sourceFile, 
			                                               String exeFile)
		{
			ICodeCompiler compiler = provider.CreateCompiler();
			String [] referenceAssemblies = {"System.dll"};
			CompilerParameters cp = new CompilerParameters(referenceAssemblies,
				exeFile, false);
			cp.GenerateExecutable = true;            
			CompilerResults cr = compiler.CompileAssemblyFromFile(cp, sourceFile);
			return cr;
		}
		//////////////////////////////////���������////////////////////////////////////
		private static void GENERATE_CODE_SERVER(CodeDomProvider provider, 
			                                     CodeCompileUnit compileunit)
		{
			String sourceFile;
			///////////////���� "TEST_CODEDOM.cs"//////////////////////////////////////
			sourceFile = "TEST_CODEDOM." + provider.FileExtension;
			/////////�������� ICodeGenerator �� CodeDomProvider////////////////////////
			ICodeGenerator gen = provider.CreateGenerator();
			///������� IndentedTextWriter, ����������� � StreamWriter ��������� ����///
			IndentedTextWriter tw = new IndentedTextWriter(new StreamWriter(sourceFile,
				false), "    ");	
			//////���������� �������� ���, ��������� ����-���������////////////////////
			gen.GenerateCodeFromCompileUnit(compileunit, tw, new CodeGeneratorOptions());
			//////////////////��������� �������� ����//////////////////////////////////
			tw.Close();            
		}
		/////////////////////////���������� ���� TEST_CODEDOM.cs///////////////////////
		public void GENERATE_CODE_CLIENT()
		{
			CodeDomProvider provider = GET_Provider();
			Console.WriteLine("��������� ���� <<TEST_CODEDOM.cs>> ����������?");
			Console.ReadLine();
			GENERATE_CODE_SERVER(provider, TEST_Build());
			Console.WriteLine("��� ������� ������!");
			Console.ReadLine();
		} 
		/////////////////////��������� ���� TEST_CODEDOM.exe///////////////////////////
		public void RUN_CODE()
		{
			Console.WriteLine("������ <<TEST_CODEDOM.EXE>> ����������?");
			Console.ReadLine();
			Process.Start("TEST_CODEDOM.exe");   
		} 
		////////////////////������� ���������� ��� ����������� CSharp//////////////////
		private CodeDomProvider GET_Provider()
		{
			CodeDomProvider provider = new CSharpCodeProvider();	
			return provider;
		}

	}
}
