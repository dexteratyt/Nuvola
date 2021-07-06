//const { remote, ipcRenderer } = require("electron");

function minimizeWindow(browserWindow = getCurrentWindow()) {
	if (browserWindow.minimizable) {
		// browserWindow.isMinimizable() for old electron versions
		browserWindow.minimize();
	}
}

function closeWindow(browserWindow = getCurrentWindow()) {
	browserWindow.close();
}

document.getElementById('closebtn').addEventListener("click", ()=>{
	closeWindow();
	console.log("Retard");
});