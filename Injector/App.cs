namespace Lunity.Injector {
	public class App {
		public static void Main(string[] args) {
			while(true) {
				IMCAGUI.Begin();
				IMCAGUI.DrawText("Hey");
				IMCAGUI.End();
			}
		}
	}
}