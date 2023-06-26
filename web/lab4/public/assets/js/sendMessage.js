function createScript(id, fullname) {
    const input = document.querySelector(`.form-control[data-id='${id}']`);
    if (input.value === "") return;

    const newScript = document.createElement("script");

    const now = new Date();
    const year = now.getFullYear();
    const month = ('0' + (now.getMonth() + 1)).slice(-2);
    const day = ('0' + now.getDate()).slice(-2);
    const hours = ('0' + now.getHours()).slice(-2);
    const minutes = ('0' + now.getMinutes()).slice(-2);
    const seconds = ('0' + now.getSeconds()).slice(-2);
    const date = `${year}-${month}-${day} ${hours}:${minutes}:${seconds}`

    newScript.src =
        "Blog/add/?id_post=" +
        id +
        "&fullname=" +
        fullname +
        "&comment=" +
        input.value +
        "&date=" +
        date;

    document.getElementsByTagName("body")[0].appendChild(newScript);
}

function addComment(data) {
    const input = document.querySelector(`.form-control[data-id='${data.id}']`);

    const commentContainer = input.parentNode.parentNode.querySelector(".commentContainer");
    commentContainer.insertAdjacentHTML(
        "afterbegin",
        `
        <div class="p-4 bg-gray-200 rounded-lg shadow-md mb-4">
            <div class="font-semibold text-lg mb-2">
                ${data.fullname}
            </div>

            <div class="text-lg mb-2">
                ${data.comment}
            </div>

            <div class="text-gray-500 text-sm mb-4">
                ${data.date}
            </div>
        </div>    
        `
    )

    // const commentContainer = input.parentNode.parentNode.parentNode.querySelector(
    //     ".card-comment__container"
    // );
    // commentContainer.insertAdjacentHTML(
    //     "afterbegin",
    //     `<div class="comment-item"><div class="d-flex"><div class="comment-item__name">${data.fullname},</div><div class="comment-item__date">${data.date}</div></div><div class="comment-item__text">${data.comment}</div></div>`
    // );

    input.value = "";
}