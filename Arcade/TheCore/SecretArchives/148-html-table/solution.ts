function solution(table: string, row: number, column: number): string {
  let t;
  return (
    ((t = table.split('<tr>')[1 + row]) &&
      (t = t.split('<td>')[1 + column]) &&
      (t = t.split('</td>')[0])) ||
    'No such cell'
  );
}
