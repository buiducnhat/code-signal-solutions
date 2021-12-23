function solution(takeOffTime, minutes) {
  let hour = +takeOffTime.substring(0, 2),
    minute = +takeOffTime.substring(3);
  minutes.unshift(0);
  if (hour == 0) hour = 24;
  let overDay = false,
    res = 0;
  for (let i = 1; i < minutes.length; i++) {
    minute += minutes[i] - minutes[i - 1];
    if (minute >= 60) {
      hour += Math.floor(minute / 60);
      minute = minute % 60;
    }
    if (hour >= 24) {
      overDay = true;
    }
    if (overDay) {
      res++;
    }
    // reset time when cross border
    hour -= 1;
    if (hour > 24 || (hour == 24 && minute != 0)) return res;
    if (hour < 24 || (hour == 24 && minute == 0)) {
      overDay = false;
    }
  }
  if (!overDay) res++;
  return res;
}
