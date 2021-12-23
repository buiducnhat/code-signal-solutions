function replaceNum(num: number): string {
  let s = '';
  for (let i = 0; i < num; ++i) {
    s += '*';
  }
  return s;
}

function rotate(matrix) {
  const N = matrix.length - 1;
  const result = matrix.map((row, i) => row.map((val, j) => matrix[N - j][i]));
  matrix.length = 0;
  matrix.push(...result);
  return matrix;
}

function solution(notation: string): string {
  let a: string[] = [];
  let rows = notation.split('/');
  for (let i = 0; i < 8; i++) {
    a.push(
      rows[i]
        .split('')
        .map((char) => {
          if (isNaN(+char)) {
            return char;
          } else {
            return replaceNum(+char);
          }
        })
        .join('')
    );
  }
  let m: string[][] = a.map((row) => row.split(''));
  m = rotate(m);
  let res: string = '';
  for (let i = 0; i < 8; i++) {
    a = [];
    for (let j = 0; j < 8; j++) {
      let count = 0;
      while (m[i][j] === '*') {
        count++;
        j++;
      }
      if (count) {
        j--;
        a.push(count + '');
      } else {
        a.push(m[i][j]);
      }
    }
    res += a.join('') + (i !== 7 ? '/' : '');
  }

  return res;
}
