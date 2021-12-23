function solution(ip: string): boolean {
  const octets = ip.split(".").map((octet) => parseInt(octet));

  if (octets.length !== 4) {
    return false;
  }

  return ip
    .split(".")
    .every(
      (octet) =>
        parseInt(octet).toString() === octet &&
        parseInt(octet) <= 255 &&
        parseInt(octet) >= 0
    );
}
