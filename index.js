const fs = require('fs/promises');
const fs2 = require('fs');

const makeSlug = (str, postfix, prefix) => {
  str = str.replace(/^\s+|\s+$/g, ''); // trim
  str = str.toLowerCase();

  // remove accents, swap ñ for n, etc
  var from = 'àáäâèéëêìíïîòóöôùúüûñç·/_,:;';
  var to = 'aaaaeeeeiiiioooouuuunc------';
  for (var i = 0, l = from.length; i < l; i++) {
    str = str.replace(new RegExp(from.charAt(i), 'g'), to.charAt(i));
  }

  str = str
    .replace(/[^a-z0-9 -]/g, '') // remove invalid chars
    .replace(/\s+/g, '-') // collapse whitespace and replace by -
    .replace(/-+/g, '-'); // collapse dashes

  postfix = postfix ? `-${postfix}` : '';
  prefix = prefix ? `${prefix}-` : '';

  return prefix + str + postfix;
};

const names = [
  'add',
  'centuryFromYear',
  'checkPalindrome',
  'adjacentElementsProduct',
  'shapeArea',
  'Make Array Consecutive 2',
  'almostIncreasingSequence',
  'matrixElementsSum',
  'All Longest Strings',
  'commonCharacterCount',
  'isLucky',
  'Sort by Height',
  'reverseInParentheses',
  'alternatingSums',
  'Add Border',
  'Are Similar?',
  'arrayChange',
  'palindromeRearranging',
  'areEquallyStrong',
  'arrayMaximalAdjacentDifference',
  'isIPv4Address',
  'avoidObstacles',
  'Box Blur',
  'Minesweeper',
  'Array Replace',
  'evenDigitsOnly',
  'variableName',
  'alphabeticShift',
  'chessBoardCellColor',
  'Circle of Numbers',
  'depositProfit',
  'absoluteValuesSumMinimization',
  'stringsRearrangement',
  'extractEachKth',
  'firstDigit',
  'differentSymbolsNaive',
  'arrayMaxConsecutiveSum',
  'growingPlant',
  'Knapsack Light',
  'longestDigitsPrefix',
  'digitDegree',
  'Bishop and Pawn',
  'isBeautifulString',
  'Find Email Domain',
  'buildPalindrome',
  'Elections Winners',
  'Is MAC48 Address?',
  'isDigit',
  'lineEncoding',
  'chessKnight',
  'deleteDigit',
  'longestWord',
  'Valid Time',
  'sumUpNumbers',
  'Different Squares',
  'digitsProduct',
  'File Naming',
  'messageFromBinaryCode',
  'spiralNumbers',
  'Sudoku',
];

async function main() {
  for (let i = 1; i <= 3; i++) {
    let dir = './Arcade/Intro/TheJourneyBegins/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 4; i <= 8; i++) {
    let dir = './Arcade/Intro/EdgeOfTheOcean/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 9; i <= 13; i++) {
    let dir = './Arcade/Intro/SmoothSailing/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 14; i <= 18; i++) {
    let dir = './Arcade/Intro/ExploringTheWaters/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 19; i <= 24; i++) {
    let dir = './Arcade/Intro/IslandOfKnowledge/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 25; i <= 29; i++) {
    let dir = './Arcade/Intro/RainsOfReason/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 30; i <= 33; i++) {
    let dir = './Arcade/Intro/ThroughTheFog/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 34; i <= 37; i++) {
    let dir = './Arcade/Intro/DivingDeeper/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 38; i <= 42; i++) {
    let dir = './Arcade/Intro/DarkWilderness/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 43; i <= 47; i++) {
    let dir = './Arcade/Intro/EruptionOfLight/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 48; i <= 51; i++) {
    let dir = './Arcade/Intro/RainbowOfClarity/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 52; i <= 60; i++) {
    let dir = './Arcade/Intro/LandOfLogic/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }
}

main();
