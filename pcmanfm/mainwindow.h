/*

    Copyright (C) 2013  Hong Jen Yee (PCMan) <pcman.tw@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef FM_MAIN_WINDOW_H
#define FM_MAIN_WINDOW_H

#include "ui_main-win.h"
#include <QtGui/QMainWindow>
#include <QListView>
#include <QSortFilterProxyModel>
#include <QLineEdit>
#include <QTabWidget>
#include <libfm/fm.h>
#include "foldermodel.h"
#include "folderview.h"
#include "placesview.h"
#include <QMessageBox>
#include <QTabBar>
#include <QStackedWidget>
#include <QSplitter>

namespace PCManFM {

class TabPage;
class Settings;

class MainWindow : public QMainWindow {
Q_OBJECT
public:
  MainWindow(FmPath* path = NULL);
  virtual ~MainWindow();

  void chdir(FmPath* path);
  void addTab(FmPath* path);

  TabPage* currentPage() {
    return reinterpret_cast<TabPage*>(ui.stackedWidget->currentWidget());
  }

  void updateFromSettings(Settings& settings);
  
protected Q_SLOTS:

  void onPathEntryReturnPressed();

  void on_actionNewTab_triggered();
  void on_actionNewWin_triggered();
  void on_actionCloseTab_triggered();
  void on_actionCloseWindow_triggered();
  void on_actionFileProperties_triggered();
  void on_actionFolderProperties_triggered();

  void on_actionCut_triggered();
  void on_actionCopy_triggered();
  void on_actionPaste_triggered();
  void on_actionDelete_triggered();
  void on_actionRename_triggered();
  void on_actionSelectAll_triggered();
  void on_actionInvertSelection_triggered();
  void on_actionPreferences_triggered();
  
  void on_actionGoBack_triggered();
  void on_actionGoForward_triggered();
  void on_actionGoUp_triggered();
  void on_actionHome_triggered();
  void on_actionReload_triggered();

  void on_actionIconView_triggered();
  void on_actionCompactView_triggered();
  void on_actionDetailedList_triggered();
  void on_actionThumbnailView_triggered();

  void on_actionGo_triggered();
  void on_actionShowHidden_triggered(bool check);

  void on_actionByFileName_triggered(bool checked);
  void on_actionByMTime_triggered(bool checked);
  void on_actionByOwner_triggered(bool checked);
  void on_actionByFileType_triggered(bool checked);
  void on_actionByFileSize_triggered(bool checked);
  void on_actionAscending_triggered(bool checked);
  void on_actionDescending_triggered(bool checked);
  void on_actionFolderFirst_triggered(bool checked);
  void on_actionCaseSensitive_triggered(bool checked);

  void on_actionApplications_triggered();
  void on_actionComputer_triggered();
  void on_actionTrash_triggered();
  void on_actionNetwork_triggered();
  void on_actionDesktop_triggered();
  void on_actionAddToBookmarks_triggered();
  void on_actionEditBookmarks_triggered();
  
  void on_actionAbout_triggered();

  void onBookmarkActionTriggered();
  
  void onTabBarCloseRequested(int index);
  void onTabBarCurrentChanged(int index);
  
  void onStackedWidgetWidgetRemoved(int index);
  
  void onTabPageTitleChanged(QString title);
  void onTabPageStatusChanged(int type, QString statusText);
  void onTabPageOpenDirRequested(FmPath* path, int target);
  void onTabPageSortFilterChanged();

  void onSidePaneChdirRequested(int type, FmPath* path);

  void onBackForwardContextMenu(QPoint pos);
  
protected:
  // void changeEvent( QEvent * event);
  void closeTab(int index);

private:
  static void onBookmarksChanged(FmBookmarks* bookmarks, MainWindow* pThis);
  void loadBookmarksMenu();
  void updateUIForCurrentPage();
  void updateViewMenuForCurrentPage();

private:
  Ui::MainWindow ui;
  QLineEdit* pathEntry;
  QLabel* fsInfoLabel;
  FmBookmarks* bookmarks;
};

}

#endif // FM_MAIN_WINDOW_H
