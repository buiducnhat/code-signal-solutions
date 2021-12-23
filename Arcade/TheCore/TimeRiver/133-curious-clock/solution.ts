function solution(someTime: string, leavingTime: string): string {
  const time1 = new Date(someTime).getTime();
  const time2 = new Date(leavingTime).getTime();
  const timeAvg = time1*2-time2;
  return new Date(timeAvg).toISOString().replace('T', ' ').slice(0, 16);
}
