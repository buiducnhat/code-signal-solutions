bool check2ChessAdjency(string f, string s) {
  return (abs(f[0] - s[0]) <= 1 && abs(f[1] - s[1]) <= 1);
}

bool checkAmazon(string amazon, string pos, string king, bool gone=false) {
  // adjency
  if (abs(amazon[0] - pos[0]) == 1 && abs(amazon[1] - pos[1]) <= 1) {
    if (check2ChessAdjency(amazon, king)) {
      return true;
    }
    return false;
  }
  if (abs(amazon[0] - pos[0]) <= 1 && abs(amazon[1] - pos[1]) == 1) {
    if (check2ChessAdjency(amazon, king)) {
      return true;
    }
    return false;
  }

  // leap
  if (abs(amazon[0] - pos[0]) == abs(amazon[1] - pos[1])) {
    // diagonal down
    if (amazon[0] + amazon[1] == pos[0] + pos[1]) {
      if (amazon[0] + amazon[1] == king[0] + king[1]) {
        if ((king[0] > pos[0] && king[0] < amazon[0]) || (king[0] > amazon[0] && king[0] < pos[0])) {
          return false;
        } else {
          return true;
        }
      }
    } else { // diagonal up
      if (amazon[0] - amazon[1] == king[0] - king[1]) {
        if ((king[0] > pos[0] && king[0] < amazon[0]) || (king[0] > amazon[0] && king[0] < pos[0])) {
          return false;
        } else {
          return true;
        }
      }
    }
    return true;
  }

  // straight
  if (amazon[0] == pos[0] || amazon[1] == pos[1]) {
    if (amazon[0] == pos[0] && amazon[0] == king[0]) {
      return !((king[0] > pos[0] && king[0] < amazon[0]) || (king[0] > amazon[0] && king[0] < pos[0]));
    } else if (amazon[1] == pos[1] && amazon[1] == king[1]) {
      return !((king[1] > pos[1] && king[1] < amazon[1]) || (king[1] > amazon[1] && king[1] < pos[1]));
    }
    return true;
  }

  // in 2 radius
  if (abs(amazon[0] - pos[0]) == 2 && abs(amazon[1] - pos[1]) <= 2) {
    return true;
  }
  if (abs(amazon[0] - pos[0]) <= 2 && abs(amazon[1] - pos[1]) == 2) {
    return true;
  }
  return false;
}

vector<int> solution(string king, string amazon) {
  // r[0]=danger and can't move, r[1]=danger and can move,
  // r[2]=safe and can't move, r[3]=safe and can move
  vector<int> r(4);
  vector<pair<int, int>> steps = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};

  for (char i = 'a'; i <= 'h'; i++) {
    for (char j = '1'; j <= '8'; j++) {
      string black = {i, j};
      if (check2ChessAdjency(king, black)) {
        continue;
      }
      string tmp = black;
      bool canMove = false;
      for (auto step : steps) {
        black = tmp; // reset black
        black[0] += step.first;
        black[1] += step.second;
        if (black[0] < 'a' || black[0] > 'h' || black[1] < '1' || black[1] > '8') {
          continue;
        }
        if (!checkAmazon(amazon, black, king) && !check2ChessAdjency(king, black)) {
          canMove = true;
        }
      }
      if (checkAmazon(amazon, tmp, king)) {
        if (canMove) cout << tmp << "-";
        r[0] += !canMove, r[1] += canMove;
      } else {
        r[2] += !canMove, r[3] += canMove;
      }
    }
  }
  return r;
}