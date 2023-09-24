<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class BoatImage extends Model
{
    use HasFactory;

    protected $table = 'boats_images';

    protected $primaryKey = 'id';

    protected $fillable = [
        'filename'
    ];

    public function boat()
    {
        return $this->belongsTo('App\Models\Boat');
    }
}
