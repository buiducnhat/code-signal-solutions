const solution = (line) => {
  line = line.replace(/_/g, ``);
  if (line.match(/^\d+$/)) return true;
  let [match, base, num] = line.match(/^(\d+)#([\da-f]+)#$/i) || [];
  return (
    !!match &&
    ![...num].some((val) => isNaN(parseInt(val, base))) &&
    base > 1 &&
    base < 17
  );
};
