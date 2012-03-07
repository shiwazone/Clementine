/* This file is part of Clementine.
   Copyright 2012, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

class AlbumCoverLoader;
class Appearance;
class CoverProviders;
class CurrentArtLoader;
class Database;
class DeviceManager;
class GlobalSearch;
class InternetModel;
class Library;
class LibraryBackend;
class LibraryModel;
class Player;
class PlaylistBackend;
class PlaylistManager;
class PodcastBackend;
class TagReaderClient;
class TaskManager;


class Application : public QObject {
  Q_OBJECT

public:
  Application(QObject* parent = NULL);
  ~Application();

  TagReaderClient* tag_reader_client() const { return tag_reader_client_; }
  Database* database() const { return database_; }
  AlbumCoverLoader* album_cover_loader() const { return album_cover_loader_; }
  PlaylistBackend* playlist_backend() const { return playlist_backend_; }
  PodcastBackend* podcast_backend() const { return podcast_backend_; }
  Appearance* appearance() const { return appearance_; }
  CoverProviders* cover_providers() const { return cover_providers_; }
  TaskManager* task_manager() const { return task_manager_; }
  Player* player() const { return player_; }
  PlaylistManager* playlist_manager() const { return playlist_manager_; }
  CurrentArtLoader* current_art_loader() const { return current_art_loader_; }
  GlobalSearch* global_search() const { return global_search_; }
  InternetModel* internet_model() const { return internet_model_; }
  Library* library() const { return library_; }
  DeviceManager* device_manager() const { return device_manager_; }

  LibraryBackend* library_backend() const;
  LibraryModel* library_model() const;

  void MoveToNewThread(QObject* object);
  void MoveToThread(QObject* object, QThread* thread);

public slots:
  void AddError(const QString& message);

signals:
  void ErrorAdded(const QString& message);

private:
  TagReaderClient* tag_reader_client_;
  Database* database_;
  AlbumCoverLoader* album_cover_loader_;
  PlaylistBackend* playlist_backend_;
  PodcastBackend* podcast_backend_;
  Appearance* appearance_;
  CoverProviders* cover_providers_;
  TaskManager* task_manager_;
  Player* player_;
  PlaylistManager* playlist_manager_;
  CurrentArtLoader* current_art_loader_;
  GlobalSearch* global_search_;
  InternetModel* internet_model_;
  Library* library_;
  DeviceManager* device_manager_;

  QList<QObject*> objects_in_threads_;
  QList<QThread*> threads_;
};

#endif // APPLICATION_H