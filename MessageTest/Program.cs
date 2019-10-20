using System;
using System.Runtime.InteropServices;
using System.Text;

namespace MessageTest
{
    class Program
    {
        [DllImport("G:\\C++\\AutoLogin\\x64\\Release\\KeyBoardHook.dll")]
        public static extern void ReportMessage(byte[] s);
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            //ReportsMessage  Send("hello World");
            string source = "顺序不对";
            byte[] s = Encoding.Convert(Encoding.GetEncoding("UTF-8"),Encoding.Unicode,Encoding.UTF8.GetBytes(source));
            ReportMessage(s);
        }
    }

}
