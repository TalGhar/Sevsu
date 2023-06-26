const pages = [
    'Главная',
    'Обо мне',
    'Мои интересы',
    'Учёба',
    'Альбом',
    'Контакты',
    'Тест',
    'История'
];

document.addEventListener("DOMContentLoaded", () => {
    let title = document.title;
    sessionStorage.setItem(title, +sessionStorage.getItem(title) + 1);
    setCookie(title, +getCookie(title) + 1, 30);
});

function getSessionStorageHistory() {
    localStorageTable = document.getElementById("localStorage");
    for (let i = 0; i < pages.length; i++) {
        localStorageTable.innerHTML +=
            `<tr>
                <th>${i + 1}</th>
                <td>${pages[i]}</td>
                <td>${sessionStorage.getItem(pages[i]) ? sessionStorage.getItem(pages[i]) : 0}</td>
            </tr>`;
    }
}

function getLocalStorageHistory() {
    cookieTable = document.getElementById("cookie");
    for (let i = 0; i < pages.length; i++) {
        cookieTable.innerHTML +=
            `<tr>
            <th>${i + 1}</th>
            <td>${pages[i]}</td>
            <td>${getCookie(pages[i]) ? getCookie(pages[i]) : 0}</td>
        </tr>`;
    }
}

function getCookie(c_name) {
    return localStorage.getItem(c_name);
}

function setCookie(c_name, value, expiredays) {
    return localStorage.setItem(c_name, value);
}

getSessionStorageHistory()

getLocalStorageHistory()