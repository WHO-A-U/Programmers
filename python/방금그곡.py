import math
sharps={
    'C#':'1',
    'D#':'2',
    'F#':'3',
    'G#':'4',
    'A#':'5'
}

def get_time(hh_mm):
    [HH,MM] = hh_mm.split(':')
    return int(int(HH)*60+int(MM))

def convert_melody(melody):
    for i in sharps:
        melody = melody.replace(i,sharps[i])
    return melody

def get_record_info(record):
    [start,end,song_name,melody] = record.split(',')
    
    melody = convert_melody(melody)
    start_timestamp,end_timestamp = get_time(start),get_time(end)
    
    run_time = end_timestamp-start_timestamp
    
    melody = (melody*(math.ceil(run_time/len(melody))+1))[0:run_time]
    return [song_name , melody]


def solution(m, musicinfos):
    answer = '(None)'
    play_list={}
    m = convert_melody(m)
    for record in musicinfos:
        [song_name , melodys] = get_record_info(record)
        play_list[song_name]=melodys
    max_run_time=0
    max_song_title=0

    for i in play_list:
        if m in play_list[i]:
            if max_run_time <len(play_list[i]):
                answer=i
                max_run_time = len(play_list[i])


                
    return answer

