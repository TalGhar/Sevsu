<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('owners', function (Blueprint $table) {
            $table->increments('id');
            $table->string('name', 35);
            $table->string('surname', 35);
            $table->string('patron', 35);
            $table->string('email')->unique();
            $table->string('password');
            $table->timestamps();
        });

        Schema::create('boats', function (Blueprint $table) {
            $table->increments('id');
            $table->string('name', 35);
            $table->string('description');
            $table->integer('owner_id')->unsigned();
            $table->foreign('owner_id')->references('id')->on('owners');
            $table->decimal('price', 10, 2);
            $table->string('status', 20);
            $table->timestamps();
        });

        Schema::create('boats_images', function (Blueprint $table) {
            $table->increments('id');
            $table->integer('boat_id')->unsigned();
            $table->foreign('boat_id')->references('id')->on('boats');
            $table->string('filename');
            $table->timestamps();
        });

        Schema::create('clients', function (Blueprint $table) {
            $table->increments('id');
            $table->string('name', 35);
            $table->string('surname', 35);
            $table->string('patron', 35);
            $table->string('email')->unique();
            $table->string('password');
            $table->timestamps();
        });

        Schema::create('orders', function (Blueprint $table) {
            $table->increments('id');
            $table->string('type', 20);
            $table->string('status', 20);
            $table->decimal('price', 10, 2);
            $table->integer('client_id')->unsigned();
            $table->foreign('client_id')->references('id')->on('clients');
            $table->timestamps();
        });

        Schema::create('orders_boats', function (Blueprint $table) {
            $table->integer('boat_id')->unsigned();
            $table->integer('order_id')->unsigned();
            $table->foreign('boat_id')->references('id')->on('boats');
            $table->foreign('order_id')->references('id')->on('orders');
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('owners');
        Schema::dropIfExists('boats');
        Schema::dropIfExists('boats_images');
        Schema::dropIfExists('clients');
        Schema::dropIfExists('orders');
        Schema::dropIfExists('orders_boats');
    }
};
