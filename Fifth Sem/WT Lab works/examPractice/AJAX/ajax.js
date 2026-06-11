const btnAjax = document.getElementById("ajaxButton");

btnAjax.addEventListener("click", handler);

function handler() {
  console.log("Button pressed");

  // create a request constant
  const xhr = new XMLHttpRequest();

  //Open the request
  xhr.open("GET", "data.txt", true);

  // Send the request
  xhr.send();

  // what happens whent he data loads, or the data is received
  xhr.onload = function () {
    console.log(xhr.responseText);
    let va = JSON.parse(xhr.responseText);
    console.log(va);
    console.log(`${va[0].name} ${va[0].surname} ${va[0].phone}`);
    document.getElementById("demo").innerHTML = xhr.responseText;
  };
}

// The modern equivalent using Fetch API
// async function handler() {
//     try {
//         const response = await fetch('data.txt');
//         const text = await response.text();
//         console.log(text);
//     } catch (error) {
//         console.error("Error fetching file:", error);
//     }
// }
