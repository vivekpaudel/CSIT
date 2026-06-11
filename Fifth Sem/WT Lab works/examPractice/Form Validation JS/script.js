//Form validation
//
//

function validation() {
  let name = document.getElementById("username").value;
  if (name == "") {
    prompt("Enter the username");
  }
  const pattern = /^[a-zA-Z0-9._]+$/;
  if (!name.match(pattern)) {
    alert("Username Not valid");
    return false;
  } else {
    console.log("Username is valid");
  }

  //Password validation:
  //
  let passwordV = document.getElementById("password").value;
  if (passwordV == "") {
    return false;
  }

  let checkboxV = document.getElementById("checkboxEducation").checked;
  if (!checkboxV) {
    alert("Check the box");
    return false;
  }

  let radio1 = document.getElementById("genderMale").checked;
  let radio2 = document.getElementById("genderFemale").checked;
  if (radio1 == false && radio2 == false) {
    alert("Check the radio buttons");
    return false;
  }

  let numberv = document.getElementById("numberForm").value;
  if (isNaN(numberv)) {
    alert("Please enter a number");
    return false;
  }
  return true;
}
