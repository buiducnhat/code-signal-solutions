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
  'Add Two Digits',
  'Largest Number',
  'Candies',
  'Seats in Theater',
  'Max Multiple',
  'Circle of Numbers',
  'Late Ride',
  'Phone Call',
  'Reach Next Level',
  'Knapsack Light',
  'Extra Number',
  'Is Infinite Process?',
  'Arithmetic Expression',
  'Tennis Set',
  'Will You?',
  'Metro Card',
  'Kill K-th Bit',
  'Array Packing',
  'Range Bit Count',
  'Mirror Bits',
  'Second-Rightmost Zero Bit',
  'Swap Adjacent Bits',
  'Different Rightmost Bit',
  'Equal Pair of Bits',
  'Least Factorial',
  'Count Sum of Two Representations 2',
  'Magical Well',
  'Lineup',
  'Addition Without Carrying',
  'Apple Boxes',
  'Increase Number Roundness',
  'Rounders',
  'Candles',
  'Count Black Cells',
  'Create Array',
  'Array Replace',
  'First Reverse Try',
  'Concatenate Arrays',
  'Remove Array Part',
  'Is Smooth?',
  'Replace Middle',
  'Make Array Consecutive 2',
  'Is Power?',
  'Is Sum of Consecutive 2',
  'Square Digits Sequence',
  'Pages Numbering With Ink',
  'Comfortable Numbers',
  'Weak Numbers',
  'Rectangle Rotation',
  'Crossword Formation',
  'Enclose In Brackets',
  'Proper Noun Correction',
  'Is Tandem Repeat?',
  'Is Case-Insensitive Palindrome?',
  'Find Email Domain',
  'HTML End Tag By Start Tag',
  'Is MAC48 Address?',
  'Is Unstable Pair?',
  'Strings Construction',
  'Is Substitution Cipher?',
  'Create Anagram',
  'Construct Square',
  'Numbers Grouping',
  'Different Squares',
  'Most Frequent Digit Sum',
  'Number of Clans',
  'House Numbers Sum',
  'All Longest Strings',
  'House of Cats',
  'Alphabet Subsequence',
  'Minimal Number of Coins',
  'Add Border',
  'Switch Lights',
  'Timed Reading',
  'Elections Winners',
  'Integer to String of Fixed Width',
  'Are Similar?',
  'Ada Number',
  'Three Split',
  'Character Parity',
  'Reflect String',
  'New Numeral System',
  'Cipher 26',
  'Stolen Lunch',
  'Higher Version',
  'Decipher',
  'Alphanumeric Less',
  'Array Conversion',
  'Array Previous Less',
  'Pair of Shoes',
  'Combs',
  'Strings Crossover',
  'Cyclic String',
  'Beautiful Text',
  'Runners Meetings',
  'Christmas Tree',
  'File Naming',
  'Extract Matrix Column',
  'Are Isomorphic?',
  'Reverse On Diagonals',
  'Swap Diagonals',
  'Crossing Sum',
  'Draw Rectangle',
  'Volleyball Positions',
  'Star Rotation',
  'Sudoku',
  'Minesweeper',
  'Box Blur',
  'Contours Shifting',
  'Polygon Perimeter',
  'Gravitation',
  'Is Information Consistent?',
  'Correct Nonogram',
  'Shuffled Array',
  'Sort by Height',
  'Sort By Length',
  'Boxes Packing',
  'Maximum Sum',
  'Rows Rearranging',
  'Digit Difference Sort',
  'Unique Digit Products',
  'Bishop and Pawn',
  'Chess Knight Moves',
  'Bishop Diagonal',
  'Whose Turn?',
  'Chess Bishop Dream',
  'Chess Triangle',
  'Amazon Checkmate',
  'Pawn Race',
  'Valid Time',
  'Video Part',
  'Day of Week',
  'Curious Clock',
  'New Year Celebrations',
  'Regular Months',
  'Missed Classes',
  'Holiday',
  'Is Sentence Correct?',
  'Replace All Digits RegExp',
  'Swap Adjacent Words',
  'N-th Number',
  'Is Subsequence?',
  'Eye Rhyme',
  'Program Translation',
  'Repetition Encryption',
  'Bugs and Bugfixes',
  'LRC to SubRip',
  'HTML Table',
  'Chess Notation',
  'Cells Joining',
  'First Operation Character',
  'Count Elements',
  'Tree Bottom',
  'Befunge-93',
  'Pipes Game',
  'Game 2048',
  'Snake Game',
  'Tetris Game',
  'Pyraminx Puzzle',
  'Lines Game',
  'Fractal',
  'Time ASCII Representation',
];

async function main() {
  for (let i = 30; i <= 34; i++) {
    let dir = './Arcade/TheCore/LoopTunnel/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 35; i <= 42; i++) {
    let dir = './Arcade/TheCore/ListForestEdge/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 43; i <= 50; i++) {
    let dir = './Arcade/TheCore/LabyrinthOfNestedLoops/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 51; i <= 58; i++) {
    let dir = './Arcade/TheCore/BookMarket/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 59; i <= 66; i++) {
    let dir = './Arcade/TheCore/MirrorLake/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 67; i <= 79; i++) {
    let dir = './Arcade/TheCore/WellOfIntegration/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 80; i <= 87; i++) {
    let dir = './Arcade/TheCore/LabOfTransformations/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 88; i <= 97; i++) {
    let dir = './Arcade/TheCore/SpringOfIntegration/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 98; i <= 105; i++) {
    let dir = './Arcade/TheCore/ListBackwoods/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 106; i <= 113; i++) {
    let dir = './Arcade/TheCore/WaterfallOfIntegration/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 114; i <= 121; i++) {
    let dir = './Arcade/TheCore/SortingOutpost/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 122; i <= 129; i++) {
    let dir = './Arcade/TheCore/Chess Tavern/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 130; i <= 137; i++) {
    let dir = './Arcade/TheCore/TimeRiver/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 138; i <= 146; i++) {
    let dir = './Arcade/TheCore/RegularHell/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 147; i <= 154; i++) {
    let dir = './Arcade/TheCore/SecretArchives/';
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
    }
    dir += makeSlug(names[i - 1], '', i);
    if (!fs2.existsSync(dir)) {
      await fs.mkdir(dir);
      await fs.writeFile(`${dir}/solution.cpp`, '');
    }
  }

  for (let i = 155; i <= 162; i++) {
    let dir = './Arcade/TheCore/CliffsOfPain/';
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
