function solution(
  x: number,
  weekDay: string,
  month: string,
  yearNumber: number
): number {
  const weekDays = [
    'Sunday',
    'Monday',
    'Tuesday',
    'Wednesday',
    'Thursday',
    'Friday',
    'Saturday',
  ];
  const months = [
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
    'July',
    'August',
    'September',
    'October',
    'November',
    'December',
  ];

  const date = new Date(
    yearNumber,
    months.findIndex((e) => e === month) + 1,
    0
  );
  const daysOfMonth = date.getDate();
  date.setMonth(date.getMonth(), 1);
  const curMonth = date.getMonth();
  let curRes = -1;
  while (date.getDate() <= daysOfMonth && date.getMonth() === curMonth) {
    if (weekDays[date.getDay()] === weekDay) {
      console.log(date);
      x--;
      curRes = date.getDate();
    }
    if (x == 0) return curRes;
    date.setDate(date.getDate() + 1);
  }
  console.log(x, curRes);
  return x === 0 ? curRes : -1;
}
