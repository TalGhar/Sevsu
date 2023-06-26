const clock = document.getElementById('clock');

const monthNames = ['Январь', 'Февраль', 'Март', 'Апрель', 'Май', 'Июнь', 'Июль', 'Август', 'Сентябрь', 'Октябрь', 'Ноябрь', 'Декабрь'];

function updateClock() {
  const now = new Date();

  const year = now.getFullYear();
  const monthIndex = now.getMonth();
  const monthName = monthNames[monthIndex];
  const day = now.getDate().toString().padStart(2, '0');
  const hours = now.getHours().toString().padStart(2, '0');
  const minutes = now.getMinutes().toString().padStart(2, '0');
  const seconds = now.getSeconds().toString().padStart(2, '0');

  const timeString = `${hours}:${minutes}:${seconds}`;
  const dateString = `${day} ${monthName} ${year}`;

  clock.textContent = `${timeString} ${dateString}`;
}
setInterval(updateClock, 1000);