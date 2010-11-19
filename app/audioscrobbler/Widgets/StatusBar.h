/*
   Copyright 2010 Last.fm Ltd.
      - Primarily authored by Jono Cole and Micahel Coffey

   This file is part of the Last.fm Desktop Application Suite.

   lastfm-desktop is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   lastfm-desktop is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with lastfm-desktop.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "lib/unicorn/StylableWidget.h"

#include <lastfm/Track>
#include <lastfm/UserDetails>

class QLabel;

class StatusBar : public StylableWidget
{
    Q_OBJECT
    public:
        StatusBar( QWidget* parent = 0);

    private slots:
        void setStatus();

        void onGotUserInfo(lastfm::UserDetails userDetails);

        void onConnectionUp();
        void onConnectionDown();

        void onIPodDetected( QString );
        void onProcessingScrobbles();
        void onFoundScrobbles( QList<Track> );
        void onNoScrobblesFound();

        void onScrobblesCached( const QList<lastfm::Track>& tracks );
        void onScrobbleStatusChanged();

    private:
        QLabel* m_inetStatus;
        QLabel* m_mainStatus;

        int m_scrobbleCount;
};