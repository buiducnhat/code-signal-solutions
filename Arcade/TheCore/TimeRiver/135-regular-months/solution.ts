function solution(currMonth: string): string {
  const [month, year] = currMonth.split('-').map(Number);
  let curr = new Date(year, month-1, 1);
  while (1) {
      if (curr.getMonth() == 11) {
          curr = new Date(curr.getFullYear() + 1, 0, 1);
      } else {
          curr = new Date(curr.getFullYear(), curr.getMonth() + 1, 1);
      }
      if (curr.getDay()==1){
          return `${(curr.getMonth()+1).toString().padStart(2, '0')}-${curr.getFullYear()}`;
      }
  }
}
