<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Owner extends Model
{
    use HasFactory;

    protected $table = 'owners';

    protected $primaryKey = 'id';

    protected $fillable = [
        'name',
        'surname',
        'patron',
        'email',
        'password'
    ];

    public function boats()
    {
        return $this->hasMany('App\Models\Boat');
    }
}
