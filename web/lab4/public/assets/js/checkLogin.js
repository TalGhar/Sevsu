function checkUsernameAvailability() {
    var username = document.getElementById("username").value;
    var submit = document.getElementById("submit");
    var httpRequest = new XMLHttpRequest();

    httpRequest.onreadystatechange = () => {
        if (httpRequest.readyState === XMLHttpRequest.DONE) {
            if (httpRequest.status === 200) {
                var response = JSON.parse(httpRequest.responseText);
                var message = document.getElementById("usernameAvailability");
                if (response.available) {
                    message.innerHTML = "Логин доступен";
                    submit.setAttribute('type', 'submit');
                    message.style.color = "green";
                } else {
                    submit.setAttribute('type', 'button');
                    message.innerHTML = "Логин занят";
                    message.style.color = "red";
                }
            } else {
                console.log("Произошла ошибка при выполнении запроса");
            }
        }
    };
    httpRequest.open("GET", "/lab4/Auth/checkLogin/?username=" + username, true);
    httpRequest.send();
}