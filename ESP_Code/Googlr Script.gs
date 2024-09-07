var ss = SpreadsheetApp.openById('1aoCEjMbDKGZVUwft_5-seL0idBBwGF386ix6wAMeFfg');
var sheet = ss.getSheetByName('Sheet1');

function doPost(e) {
  var val = e.parameter.value;
  
  if (val !== undefined){
    var range = sheet.getRange('A2');
    range.setValue(val);
  }
}

function doGet(e) {
  var read = e.parameter.read;

  if (read !== undefined) {
    var c2Value = sheet.getRange('C2').getValue();
    var d2Value = sheet.getRange('D2').getValue();
    
    // Concatenate values with a space
    var result = c2Value + ' ' + d2Value;
    
    return ContentService.createTextOutput(result);
  }
}