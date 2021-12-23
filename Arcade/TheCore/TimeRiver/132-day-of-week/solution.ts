function solution(birthdayDate: string): number {
  const birthday = new Date(birthdayDate);
  
  let i = 0;
  while (++i) {
      const nextBirthday = new Date(birthday.getFullYear()+i, birthday.getMonth(), birthday.getDate());
      if (nextBirthday.getDay() === birthday.getDay() 
              && nextBirthday.getDate() === birthday.getDate()
              && nextBirthday.getMonth() === birthday.getMonth()) {
          break;
      }
  }
  return i; 
}
