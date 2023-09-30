<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Awards extends Model
{
    use HasFactory;

    protected $table = 'awards';
    protected $primaryKey = 'id';
    public $timestamps = false;
    protected $fillable = [
        'award_title',
        'award_text',
        'award_image'
    ];
}
