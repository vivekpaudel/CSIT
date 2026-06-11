const submitBth = document.getElementById("submitButton");

submitBth.addEventListener("click", validation);

function validation(event) {
  let phoneV = document.getElementById("phoneNumber").value;
  let nameV = document.getElementById("name").value;
  var pattern = /^[a-zA-Z\s]+$/;
  let isvalid = true;
  if (nameV == "") {
    alert("Please enter the name");
    isvalid = false;
  } else if (!nameV.match(pattern)) {
    alert("Only name characters allowed");
    isvalid = false;
  }

  if (phoneV == "") {
    alert("Please enter the phone number");
    isvalid = false;
  } else if (isNaN(phoneV)) {
    alert("Only number allowded in phone");
    isvalid = false;
  }
  if (!isvalid) {
    event.preventDefault();
  }
}
