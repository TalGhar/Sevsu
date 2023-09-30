<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class News extends Model
{
    use HasFactory;

    protected $table = 'news';
    protected $primaryKey = 'id';
    public $timestamps = true;
    protected $fillable = [
        'news_title',
        'news_text',
        'news_image'
    ];
}
