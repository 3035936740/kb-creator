//
// Created by Bing on 2023/11/22.
//

#include "BackgroundMusic.hpp"

kbc::other::BackgroundMusic::BackgroundMusic() = default;

kbc::other::BackgroundMusic::~BackgroundMusic() = default;

kbc::other::BackgroundMusic::BackgroundMusic(const kbc::other::BackgroundMusic& music){
    *this = music;
}

kbc::other::BackgroundMusic::BackgroundMusic(kbc::other::BackgroundMusic&& music) noexcept {
    *this = std::move(music);
}

kbc::other::BackgroundMusic& kbc::other::BackgroundMusic::operator=(const kbc::other::BackgroundMusic& music){
    if (this == &music)
        return *this;
    *this = music;
    return *this;
}

kbc::other::BackgroundMusic& kbc::other::BackgroundMusic::operator=(kbc::other::BackgroundMusic&& music) noexcept {
    if (this == &music)
        return *this;
    *this = std::move(music);
    return *this;
}


void kbc::other::BackgroundMusic::setMusic(std::filesystem::path&& filename, sf::Time&& start, sf::Time&& end){
    this->m_music_info.audioPath = filename;
    this->m_music_info.start_pos = start;
    this->m_music_info.end_pos = end;
    this->m_is_modify_music = true;

}
bool kbc::other::BackgroundMusic::checkMusicModify(){
    if (this->m_is_modify_music){
        this->m_is_modify_music = false;
        return true;
    }
    return false;
}

kbc::core::define::BackgroundMusic& kbc::other::BackgroundMusic::getMusic() {
    return this->m_music_info;
}

void kbc::other::BackgroundMusic::loopDetection(){
    if (this->checkMusicModify()){
        this->m_music.stop();

        if (!this->m_music.openFromFile(this->m_music_info.audioPath.string())){
            std::runtime_error("The audio path does not exist");
        }
        this->m_music.play();
    }

    if (this->m_music.getPlayingOffset() > this->m_music_info.end_pos) {
        this->m_music.setPlayingOffset(this->m_music_info.start_pos);
    }
}