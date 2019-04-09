#include "BaseballCardCollectionWindow.h"

using namespace view;

// TODO (zach#1#): Rename Model, Utils, View, Others folders to use all lower case per instructions.

int main (int argc, char ** argv)
{
    BaseballCardCollectionWindow mainWindow(540, 375, "Zachary LaVere's Baseball Card Collection");
    mainWindow.show();

    int exitCode = Fl::run();
    return exitCode;
}
