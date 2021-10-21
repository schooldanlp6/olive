/***
  Olive - Non-Linear Video Editor
  Copyright (C) 2021 Olive Team
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

#include "markerundo.h"

namespace olive {

MarkerAddCommand::MarkerAddCommand(Project *project, TimelineMarkerList *marker_list, const TimeRange &range, const QString &name, int color) :
    project_(project),
    marker_list_(marker_list),
    range_(range),
    name_(name),
    color_(color)
{
}

Project* MarkerAddCommand::GetRelevantProject() const 
{
  return project_;
}

void MarkerAddCommand::redo()
{
  added_marker_ = marker_list_->AddMarker(range_, name_, color_);
}

void MarkerAddCommand::undo()
{
  marker_list_->RemoveMarker(added_marker_);
}

MarkerRemoveCommand::MarkerRemoveCommand(Project *project, TimelineMarker *marker, TimelineMarkerList *marker_list) :
    project_(project),
    marker_(marker),
    marker_list_(marker_list),
    range_(marker->time()),
    name_(marker->name()),
    color_(marker->color())
{
}

Project* MarkerRemoveCommand::GetRelevantProject() const
{
  return project_;
}

void MarkerRemoveCommand::redo()
{
  marker_list_->RemoveMarker(marker_);
}

void MarkerRemoveCommand::undo()
{
  marker_list_->AddMarker(range_, name_, color_);
}

}