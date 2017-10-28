using System;
using System.CodeDom;
using System.CodeDom.Compiler;
using Microsoft.CSharp;
using System.Reflection;
namespace ConsoleApplication1
{
	class Class1
	{
		[STAThread]
		static void Main(string[] args)
		{
			CSharpCodeProvider codeProvider= new CSharpCodeProvider();
			ICodeCompiler ic= codeProvider.CreateCompiler();	
			//////////////��������� ����������////////////////////////////////////
			CompilerParameters cp= new CompilerParameters();
			cp.ReferencedAssemblies.Add("System.dll");
			cp.GenerateExecutable= false; //�� ������� ����������� ������
			cp.GenerateInMemory= true;    //���������� � ������
			//////////////////�����������/////////////////////////////////////////
     		CompilerResults cr = ic.CompileAssemblyFromFile(cp,"test.cs"); 
            //////////������� ������ � ����������� ��/////////////////////////////
			Assembly My_Assembly = cr.CompiledAssembly;
            My_Assembly.GetType("TEST_Class").InvokeMember("Main", BindingFlags.InvokeMethod, null, null, new object [] {});
		}
	}
}
