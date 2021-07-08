using ConsoleGUI;
using ConsoleGUI.Controls;
using ConsoleGUI.Space;

namespace Lunity.Injector {
	public class App {
		public static void Main(string[] args) {
			ConsoleManager.Content = new TextBlock { Text = "Hello world" };
			ConsoleManager.Console = new SimplifiedConsole();
		}
	}
}