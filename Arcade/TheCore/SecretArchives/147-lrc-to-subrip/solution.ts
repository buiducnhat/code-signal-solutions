function convertTime(str: string) {
  let date = new Date(new Date().setHours(0, 0, 0, 0));
  const minute = str.substr(1, 2);
  const second = str.substr(4, 2);
  const xx = str.substr(7, 2);
  date.setMinutes(+minute, +second);
  return (
    date.getHours().toString().padStart(2, '0') +
    ':' +
    date.getMinutes().toString().padStart(2, '0') +
    ':' +
    date.getSeconds().toString().padStart(2, '0') +
    ',' +
    xx.toString().padEnd(3, '0')
  );
}

function solution(lrcLyrics: string[], songLength: string): string[] {
  const res: string[] = [];
  for (let i = 0; i < lrcLyrics.length - 1; i++) {
    const durationTime =
      convertTime(lrcLyrics[i]) + ' --> ' + convertTime(lrcLyrics[i + 1]);
    res.push(i + 1 + '', durationTime, lrcLyrics[i].substring(11), '');
  }
  const durationTime =
    convertTime(lrcLyrics[lrcLyrics.length - 1]) +
    ' --> ' +
    songLength +
    ',000';
  res.push(
    lrcLyrics.length + '',
    durationTime,
    lrcLyrics[lrcLyrics.length - 1].substring(11)
  );

  return res;
}
