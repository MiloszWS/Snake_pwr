#include "BoardTextView.h"
#include "SnakeTextView.h"
#include "SFMLview.h"
#include "SFMLcontroller.h"
#include "otherWindows.h"
#include "scoreScreen.h"

using namespace std;

int main() {

    BoardTextView board(20,20);
    SnakeTextView view1(board);
    SFMLview view (view1, board);
    otherWindows view2(view1, board);
    scoreScreen view3(board, view1);
    SFMLcontroller ctrl(view1, view, view2, view3);
    ctrl.play();

    return 0;
}