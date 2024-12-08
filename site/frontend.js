let textField = document.getElementsByClassName("trajectory");

let data = [0,0];
//fetching data.....

let printString = "<p class='traj'>" + 0 + " meters from start, " + 0 + " meters above the ground." + "</p>";
let printCode = printString;
let scale = 1000;
for (let i = 0; i < scale; i++) {
    printCode += printString;
}
textField.innerHTML = printCode;
