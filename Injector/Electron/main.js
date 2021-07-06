const { app, BrowserWindow, ipcMain } = require('electron');

function createWindow() {
	const win = new BrowserWindow({
		width: 800,
		height: 600,
		//frame: false
		webPreferences: {
			nodeIntegration: true
		}
	});

	win.loadFile('Main/index.html');
}

app.whenReady().then(() => {
	createWindow();
});

app.on('window-all-closed', function() {
	app.quit();
});