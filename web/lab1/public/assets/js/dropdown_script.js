const dropdown = document.getElementById("dropdown");
const dropdownList = document.getElementById("dropdownList");

dropdown.addEventListener("mouseover", () => {
    dropdownList.classList.remove
        ("hidden");
});

dropdown.addEventListener("mouseout", () => {
    dropdownList.classList.add
        ("hidden");
});