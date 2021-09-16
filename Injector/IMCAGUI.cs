//IMCAGUI - Immediate Mode Console App Graphical User Interface
//Yes, this is stupid

using System;
using System.Threading;

namespace Nuvola.Injector {
	public class IMCAGUI {
		public static void Begin() {
			Console.Clear();
			Console.SetCursorPosition(0,0);
		}
		public static void SetColor(int rgb) {
			
		}
		public static void DrawText(string text) {
			Console.WriteLine(text);
		}
		public static void End() {
			Thread.Sleep(100);
		}
	}
}