<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Order extends Model
{
    use HasFactory;

    protected $table = 'orders';

    protected $primaryKey = 'id';

    protected $fillable = [
        'type',
        'status',
        'price'
    ];

    public function client()
    {
        return $this->belongsTo('App\Models\Client');
    }

    public function boats()
    {
        return $this->belongsToMany('App\Models\Boat');
    }
}
