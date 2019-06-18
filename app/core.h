/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef CORE_H
#define CORE_H

#include "window/mainwindow/mainwindow.h"

/**
 * @brief The Core class
 *
 * The main Olive application instance. This runs both in GUI and CLI modes (and handles what to init based on that).
 * It also contains various global functions/variables for use throughout Olive.
 */
class Core : public QObject
{
  Q_OBJECT
public:
  /**
   * @brief Core Constructor
   *
   * Currently empty
   */
  Core();

  /**
   * @brief Start Olive Core
   *
   * Main application launcher. Parses command line arguments and constructs main window (if entering a GUI mode).
   */
  void Start();

  /**
   * @brief Stop Olive Core
   *
   * Ends all threads and frees all memory ready for the application to exit.
   */
  void Stop();

  /**
   * @brief Retrieve main window instance
   *
   * @return
   *
   * Pointer to the olive::MainWindow object, or nullptr if running in CLI mode.
   */
  olive::MainWindow* main_window();
private:
  /**
   * @brief Internal main window object
   */
  olive::MainWindow* main_window_;

  /**
   * @brief Internal startup project object
   *
   * If the user specifies a project file on the command line, the command line parser in Start() will write the
   * project URL here to be loaded once Olive has finished initializing.
   */
  QString startup_project_;
};

namespace olive {
/**
 * @brief Core object accessible from anywhere in the code
 *
 * Use this to access Core functions.
 */
extern Core core;
}

#endif // CORE_H
