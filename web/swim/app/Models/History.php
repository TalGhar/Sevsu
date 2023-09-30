<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class History extends Model
{
    use HasFactory;

    protected $table = 'history';

    protected $primaryKey = 'id';
    public $timestamps = false;

    protected $fillable = [
        'history_text'
    ];
}
