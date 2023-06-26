<?php
class InterestsModel extends Model
{
    public function get_data()
    {
        return [
            [
                'id' => 'Games',
                'img' => 'public/assets/img/poe.png',
                'description' => 'Который год... Всё повторяется'
            ],

            [
                'id' => 'Books',
                'img' => 'public/assets/img/pelevin.jpg',
                'description' => 'Тут особо говорить и нечего. Гениальный человек, но понять не всем дано.'
            ],

            [
                'id' => 'Music',
                'img' => 'public/assets/img/mane.jpg',
                'description' => 'Ну а тут базовый испольнитель'
            ]
        ];
    }
}