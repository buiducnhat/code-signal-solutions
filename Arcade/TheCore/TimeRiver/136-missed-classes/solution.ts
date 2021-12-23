function solution(year: number, daysOfTheWeek: number[], holidays: string[]): number {
  let count = 0;
  holidays.forEach((holiday)=>{
      const date = new Date(year, +holiday.substr(0, 2)-1, +holiday.substr(3));
      if (date.getMonth() <= 4) {
          date.setFullYear(date.getFullYear()+1);
      }
      count += daysOfTheWeek.includes(date.getDay() || 7) ? 1 : 0;            
  });
  return count;
}
