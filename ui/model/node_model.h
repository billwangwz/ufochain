// Copyright 2018 The UFO Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License

#pragma once

#include <QThread>
#include <memory>
#include <atomic>
#include <condition_variable>
#include "core/block_crypt.h"
#include "node/node.h"
#include "node/node_client.h"
#include "utility/io/errorhandling.h"
#include "utility/io/reactor.h"
#include "wallet/common.h"

class NodeModel 
    : public QObject
    , private ufo::INodeClientObserver
{
    Q_OBJECT
public:

    NodeModel();

    void setKdf(ufo::Key::IKdf::Ptr);
    void setOwnerKey(ufo::Key::IPKdf::Ptr);
    void startNode();
    void stopNode();

    void start();

    bool isNodeRunning() const;

signals:
    void initProgressUpdated(quint64 done, quint64 total);
    void syncProgressUpdated(int done, int total);
    void startedNode();
    void stoppedNode();
    void failedToStartNode(ufo::wallet::ErrorType errorType);
    void failedToSyncNode(ufo::wallet::ErrorType errorType);
    void createdNode();
    void destroyedNode();

protected:
    void onInitProgressUpdated(uint64_t done, uint64_t total) override;
    void onSyncProgressUpdated(int done, int total) override;
    void onStartedNode() override;
    void onStoppedNode() override;
    void onFailedToStartNode(ufo::io::ErrorCode errorCode) override;
    void onSyncError(ufo::Node::IObserver::Error error) override;
    void onNodeCreated() override;
    void onNodeDestroyed() override;

    uint16_t getLocalNodePort() override;
    std::string getLocalNodeStorage() override;
    std::string getTempDir() override;
    std::vector<std::string> getLocalNodePeers() override;

    void onNodeThreadFinished() override;

private:
    ufo::NodeClient m_nodeClient;
};
