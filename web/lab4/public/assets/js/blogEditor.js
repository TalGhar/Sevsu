const editBtn = document.getElementsByClassName("edit-btn");
const modal = document.querySelector(".modal");
const container = modal.querySelector(".container");

const modalTitle = document.getElementById("editTitle");
const modalMessage = document.getElementById("editMessage");
const modalErrorBlock = document.getElementById("modalErrorBlock");

let currentPost = {};

modal.addEventListener("click", e => {
    if (e.target !== modal && e.target !== container) return;
    modal.classList.add("hidden");
});

for (let i = 0; i < editBtn.length; i++) {
    editBtn[i].addEventListener("click", e => {
        currentPost = {
            id: e.currentTarget.getAttribute("data-id"),
            title: e.currentTarget.getAttribute("data-title"),
            message: e.currentTarget.getAttribute("data-message")
        };
        modalTitle.value = currentPost.title;
        modalMessage.value = currentPost.message;
        modal.classList.remove("hidden");
        document.getElementById("saveBtn").addEventListener("click", saveChanges);
    });
}

const saveChanges = () => {
    const xmlString = "<profile>" +
    "  <id>" + currentPost.id + "</id>" +
    "  <title>" + modalTitle.value + "</title>" +
    "  <message>" + modalMessage.value + "</message>" +
    "</profile>";

    console.log(xmlString);
    let httpRequest = new XMLHttpRequest();

    httpRequest.open("POST", "BlogEditor/edit", true);
    httpRequest.setRequestHeader("Content-Type", "text/xml; charset=UTF-8");
    httpRequest.send(xmlString);

    httpRequest.onreadystatechange = () => {
        if (httpRequest.readyState == XMLHttpRequest.DONE) {
            if (httpRequest.status == 200) {
                var response = JSON.parse(httpRequest.response);
                modalErrorBlock.innerHTML = "";
                if (response.length) {

                    response.forEach(err => {
                        const errorDiv = document.createElement("p");
                        errorDiv.className = "result-block__item error";
                        errorDiv.innerHTML = err;
                        modalErrorBlock.appendChild(errorDiv);
                    });
                } else {

                    const currentBtn = document.querySelectorAll(
                        `.btn.edit-btn[data-id="${currentPost.id}"]`
                    )[0];
                    const title = currentBtn.parentNode.getElementsByTagName(
                        "h2"
                    )[0];
                    const text = currentBtn.parentNode.getElementsByTagName("p")[0];
                    console.log(text);
                    title.innerHTML = modalTitle.value;
                    text.innerHTML = modalMessage.value;
                    currentBtn.setAttribute("data-title", modalTitle.value);
                    currentBtn.setAttribute("data-message", modalMessage.value);
                    modal.classList.add("hidden");
                }
            }
        }
    };
};