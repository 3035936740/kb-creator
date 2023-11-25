//
// Created by Bing on 2023/11/23.
//

#include "FramePerSecond.hpp"

#include <utility>

void kbc::utils::FramePerSecond::setFrames(std::chrono::microseconds fps) {
    if (this->m_mutex){
        std::unique_lock<std::mutex> lock(*this->m_mutex);
        this->m_frames = fps;
    } else this->m_frames = fps;
}

const std::chrono::microseconds &kbc::utils::FramePerSecond::getFrames() {
    return this->m_frames;
}

kbc::utils::FramePerSecond::FramePerSecond(FramePerSecond&& framePerSecond) noexcept {
    *this = std::move(framePerSecond);
}

kbc::utils::FramePerSecond &kbc::utils::FramePerSecond::operator=(const FramePerSecond& framePerSecond) {
    if (this == &framePerSecond)
        return *this;
    *this = framePerSecond;
    return *this;
}

kbc::utils::FramePerSecond &kbc::utils::FramePerSecond::operator=(FramePerSecond&& framePerSecond) noexcept {
    if (this == &framePerSecond)
        return *this;
    *this = std::move(framePerSecond);
    return *this;
}


kbc::utils::FramePerSecond::FramePerSecond(std::shared_ptr<std::mutex> pmutex) : m_mutex{pmutex} {
}

void kbc::utils::FramePerSecond::setMutex(std::shared_ptr<std::mutex> pmutex) {
    this->m_mutex = pmutex;
}

kbc::utils::FramePerSecond::FramePerSecond(const kbc::utils::FramePerSecond &framePerSecond) {
    *this = framePerSecond;
}

kbc::utils::FramePerSecond::~FramePerSecond() {
    m_mutex.reset();
}

kbc::utils::FramePerSecond::FramePerSecond(std::chrono::microseconds&& fps) : m_frames {fps} {}

kbc::utils::FramePerSecond::FramePerSecond(const std::chrono::microseconds& fps) : m_frames {fps} {}

kbc::utils::FramePerSecond::FramePerSecond(std::chrono::microseconds fps, std::shared_ptr<std::mutex> pmutex):
FramePerSecond(pmutex){
    this->m_frames = std::forward<std::chrono::microseconds>(fps);
}

kbc::utils::FramePerSecond::FramePerSecond() = default;
